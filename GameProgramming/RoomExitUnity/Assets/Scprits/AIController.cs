using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public struct Timmer
{
    public float m_fMaxTime;
    public float m_fCurTime;

    public Timmer(float maxTime = 10)
    {
        m_fCurTime = -1;
        m_fMaxTime = maxTime;
    }

    public void UpdateTimmer()
    {
        if (m_fCurTime > -1)
            m_fCurTime += Time.deltaTime;
    }

    public void StartTimmer()
    {
        m_fCurTime = 0;
    }

    public void StopTimmer()
    {
        m_fCurTime = -1;
    }

    public void ResetTimmer()
    {
        m_fCurTime -= m_fMaxTime;
    }

    public bool CheckTimmer(bool loop = true)
    {
        if (m_fCurTime >= m_fMaxTime)
        {
            if (loop)
                ResetTimmer();
            else
                StopTimmer();
            return true;
        }
        return false;
    }
}

public class AIController : Controller
{
    public enum E_AI_STATE { ATTAK, MOVE, SEARCH, LOOKAT }
    public E_AI_STATE m_eCurState;

    Timmer m_sAttackTimmer;

    public float m_fSite;
    public float m_fAttackAngle;

    public float m_fRotAngle;
    public float m_fCurRotAngle;
    public Vector3 m_vRotAsix;

    public NavMeshAgent m_navMashAgent;

    public void SetState(E_AI_STATE state)
    {
        switch (state)
        {
            case E_AI_STATE.ATTAK:
                m_navMashAgent.SetDestination(this.transform.position);
                m_sAttackTimmer = new Timmer(1);
                Player.Attack();
                m_sAttackTimmer.StartTimmer();
                break;
            case E_AI_STATE.MOVE:
                //만약, 회전시 생길수있는 오차를 보정하기위해서 사용함.
                if (CheckTarget())
                {
                    Vector3 vTargetPos = Player.m_colliderTarget.transform.position;
                    vTargetPos.y = transform.position.y;
                    transform.LookAt(vTargetPos);
                }
                break;
            case E_AI_STATE.SEARCH:

                break;
            case E_AI_STATE.LOOKAT:
                if (CheckTarget())
                {
                    Vector3 vDir = transform.forward;
                    Vector3 vPos = transform.position;
                    Vector3 vTargetPos = Player.m_colliderTarget.gameObject.transform.position;
                    vTargetPos.y = transform.position.y;
                    Vector3 vToTarget = vTargetPos - vPos;

                    float fAngle = Vector3.Angle(vDir, vToTarget.normalized);
                    float fDot = Vector3.Dot(vDir, vToTarget.normalized);
                    float fRad = Mathf.Acos(fDot);
                    if (fDot > 0) //각도의 방향에 따라 축을 변경하여, 
                        m_vRotAsix = Vector3.up; //시계방향
                    else
                        m_vRotAsix = Vector3.down; //반시계방향
                    m_fRotAngle = Mathf.Rad2Deg * fRad;//라디안을 각도로 변환
                    m_fCurRotAngle = 0;
                }
                else
                {
                    SetState(E_AI_STATE.SEARCH);
                }
                break;
        }
        m_eCurState = state;
    }

    public void UpdateState()
    {
        ActionFindNear();
        if (!CheckTarget()) SetState(E_AI_STATE.SEARCH);

        switch (m_eCurState)
        {
            case E_AI_STATE.ATTAK:
                {
                    //if (CheckRaycastForword("Player", Player.AttakRange))
                    if(CheckArcForword(Player.m_colliderTarget))
                    {
                        m_sAttackTimmer.UpdateTimmer();
                        if (m_sAttackTimmer.CheckTimmer())
                        {
                            if (!Player.Attack())
                                Player.m_cGun.Reload();
                        }
                    }
                    else
                        SetState(E_AI_STATE.LOOKAT);
                }
                break;
            case E_AI_STATE.MOVE:
                {
                    if (CheckRaycastForword("Player",m_fSite))
                    {
                        Vector3 vPos = transform.position;
                        Vector3 vTargetPos = Player.m_colliderTarget.transform.position;

                        float fDist = Vector3.Distance(vPos, vTargetPos);
                        if (fDist > Player.AttakRange)
                        {
                            m_navMashAgent.SetDestination(vTargetPos);
                            Rigidbody.velocity = Vector3.zero;
                        }
                        //Translate(Vector3.forward,Dynamic.Speed);
                        else
                            SetState(E_AI_STATE.ATTAK);
                    }
                    else
                        SetState(E_AI_STATE.LOOKAT);
                }
                break;
            case E_AI_STATE.SEARCH:
                if (CheckTarget())
                {
                    if(!CheckRaycastBetween("Wall",transform.position, Player.m_colliderTarget.transform.position ))
                    //if(ActionCheckWall() != E_ACTION_RESURT.SUCCESS)
                        SetState(E_AI_STATE.LOOKAT);
                }
                break;
            case E_AI_STATE.LOOKAT:
                if (m_fCurRotAngle <= m_fRotAngle)
                {
                    Rotation(m_vRotAsix, Player.AngleSpeed);
                    m_fCurRotAngle += Player.AngleSpeed;
                }
                else
                {
                    SetState(E_AI_STATE.MOVE);
                }
                break;
        }
    }

    public enum E_ACTION_RESURT { FAILURE = -1, RUNNING,  SUCCESS  }

    public E_ACTION_RESURT BooleanToActionResult(bool check)
    {
        return check ? E_ACTION_RESURT.SUCCESS : E_ACTION_RESURT.FAILURE;
    }

    public E_ACTION_RESURT ActionFindNear()
    {
        Collider collider = ProcessFindNearCollider("Player");
       
        Player.m_colliderTarget = collider;
        return E_ACTION_RESURT.RUNNING;
    }
    public E_ACTION_RESURT ActionCheckWall()
    {

        Vector3 vPos = transform.position;
        Vector3 vTarget = Player.m_colliderTarget.transform.position;

        if (CheckRaycastBetween("Wall", vPos, vTarget))
        {
            Player.m_colliderTarget = null;
            return E_ACTION_RESURT.SUCCESS;
        }

        return E_ACTION_RESURT.RUNNING;
    }

    public E_ACTION_RESURT ActionLookAt()
    {
        if (m_fCurRotAngle <= m_fRotAngle)
        {
            Rotation(m_vRotAsix, Player.AngleSpeed);
            m_fCurRotAngle += Player.AngleSpeed;
            return E_ACTION_RESURT.RUNNING;
        }
        else
            return E_ACTION_RESURT.SUCCESS;
    }

    public E_ACTION_RESURT ActionMoveToTarget()
    {
        if (CheckAttakRange())
            return E_ACTION_RESURT.SUCCESS;
        else
            return E_ACTION_RESURT.RUNNING;
    }

    public bool CheckTarget()
    {
        return Player.m_colliderTarget ? true : false;
    }

    public bool CheckArcForword(Collider collider)
    {
        Vector3 vPos = transform.position;
        Vector3 vColPos = collider.transform.position;
        Vector3 vForword = transform.forward;

        Vector3 vDist = vColPos - vPos;
        float fDist = vDist.magnitude;

        if (fDist <= m_fSite)
        {
            float fColAngle = Vector3.Angle(vForword, vDist.normalized);
            float fHalfAngle = m_fAttackAngle * 0.5f;
            Debug.DrawLine(vPos, vPos + vForword * m_fSite, Color.blue);
            Vector3 vRight = Quaternion.Euler(Vector3.up * fHalfAngle) * vForword;
            Debug.DrawLine(vPos, vPos + vRight * m_fSite, Color.red);
            Vector3 vLeft = Quaternion.Euler(Vector3.down * fHalfAngle) * vForword;
            Debug.DrawLine(vPos, vPos + vLeft * m_fSite, Color.red);

            if (fColAngle <= fHalfAngle)
            {
                return true;
            }
        }
        return false;
    }

    public bool CheckRaycastForword(string strLayerName, float dist)
    {
        Vector3 vPos = transform.position;
        vPos.y = Player.transform.position.y;
        Ray ray = new Ray(vPos, transform.forward);
        Debug.DrawLine(vPos, vPos + ray.direction * dist);
        return Physics.Raycast(ray, dist, 1 << LayerMask.NameToLayer(strLayerName));
    }

    public bool CheckRaycastBetween(string strLayerName, Vector3 vPos, Vector3 vTarget)
    {
        vPos.y = Player.transform.position.y;
        Vector3 vDist = vTarget - vPos;
        Ray ray = new Ray(vPos, vDist.normalized);
        Debug.DrawLine(vPos, vTarget);
        return Physics.Raycast(ray, vDist.magnitude, 1 << LayerMask.NameToLayer(strLayerName));
    }

    public bool CheckAttakRange()
    {
        Vector3 vPos = transform.position;
        Vector3 vTargetPos = Player.m_colliderTarget.transform.position;

        float fDist = Vector3.Distance(vPos, vTargetPos);
        if (fDist > Player.AttakRange) return false;
        return true;
    }

    public Collider ProcessFindNearCollider(string strLayerName)
    {
        int nLayer = 1 << LayerMask.NameToLayer(strLayerName);
        Collider[] colliders = Physics.OverlapSphere(this.transform.position, m_fSite, nLayer);

        Collider colliderMin = null;
        float fPreDist = 99999999.0f;
        //찾은대상중 가장 가까운 대상을 찾는다.
        for (int i = 0; i < colliders.Length; i++)
        {
            Collider collider = colliders[i];
            float fDist = Vector3.Distance(collider.transform.position, this.transform.position);

            if (colliderMin == null || fPreDist > fDist)
                colliderMin = collider;
            fPreDist = fDist;
            //Debug.Log(string.Format("[{0}]{1}:{2}", i, collider.gameObject.name, fDist));
        }

        return colliderMin;
    }

    private void Awake()
    {
        m_navMashAgent = GetComponent<NavMeshAgent>();
        base.GetRigidbody();
    }

    // Start is called before the first frame update
    void Start()
    {
        SetState(m_eCurState);
    }

    // Update is called once per frame
    void Update()
    {
        UpdateState();
    }

    private void OnDrawGizmos()
    {
        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(this.transform.position, m_fSite);
    }
}
