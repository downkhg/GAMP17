using UnityEngine;

public class SimpleRigidBody : MonoBehaviour
{
    public float m_fGravity = 9.8f;
    public Vector3 m_fGravityDir = Vector3.down;
    public Vector3 m_vVelocity;

    public bool m_isGround = false;
    public Vector3 m_vGroudPos;

    public LayerMask m_sLayerMask;
   
    public void AddForce(Vector3 dir, float power)
    {
        m_vVelocity += dir * power;
    }
    private void Update()
    {
        
    }

    private void FixedUpdate()
    {
        ProcessGravity();
        //ProcessNoCollisionGravity();
    }

    void ProcessGravity()
    {
        Vector3 vPos = transform.position;
        float fRad = 0.5f;
        Vector3 vSpherePos = vPos;
        vSpherePos.y += fRad;

        //바닥과의 충돌체크하여 현재 충돌상태를 확인한다.
        Collider[] collider = Physics.OverlapSphere(vSpherePos, fRad, m_sLayerMask);
        bool isCollision = false;
        if (collider.Length > 0)
            isCollision = true;

        Vector3 vGravity = new Vector3();
        if(!isCollision && !m_isGround)
        {
            vGravity = m_fGravityDir * m_fGravity;
        }
        m_vVelocity += vGravity;
        transform.position += m_vVelocity * Time.deltaTime;
        
        //물체의 위치가 이동한 뒤에는 이미 바닥에 꺼져있을수도 있으므로
        //미래의 위치를 충돌체크해 상태를 판단한다.
        Ray ray = new Ray(transform.position, m_vVelocity.normalized);
        float fDist = m_vVelocity.magnitude * Time.deltaTime;
        RaycastHit raycastHit;
        Vector3 vGroundPos = ray.origin;
        bool isNextCollision;

        if (Physics.Raycast(ray, out raycastHit, fDist, m_sLayerMask))
        {
            vGroundPos = raycastHit.point;
            isNextCollision = true;
        }
        else
        {
            vGroundPos.y = -99999.0f;//바닥위치를 꺼트린다.
            isNextCollision = false;
        }

        //Enter: 현재상태가 충돌되지않고, 다음상태가 충돌됨.
        if (!isCollision && isNextCollision)
        {
            m_isGround = true;
            SetEnterGround(transform.position, m_vGroudPos.y);
            Debug.Log("Ground Enter!");
        }
        //Exit: 이전상태가 충돌되고, 다음상태가 충돌되지않음.
        else if (isCollision && !isNextCollision)
        {
            m_isGround = false;
            Debug.Log("Ground Exit!");
        }
    }

    private void OnDrawGizmos()
    {
        //Gizmos.DrawSphere(this.transform.position, m_fGravity * Time.deltaTime);
        float rad = 0.5f;
        Vector3 vPosDown = transform.position + Vector3.up * rad;
        Gizmos.color = Color.blue;
        Gizmos.DrawWireSphere(vPosDown, rad);
    }

    void ProcessNoCollisionGravity(float groundY)
    {
        float fDeltaTime = Time.deltaTime;
        Vector3 vPos = transform.position;
 
        if (vPos.y >= groundY)
        {
            if (vPos.y > groundY)
                m_vVelocity += m_fGravityDir * m_fGravity;// * fDeltaTime;

            transform.position += m_vVelocity * fDeltaTime;
        }
        else
        {
            SetEnterGround(vPos, groundY);
        }
    }

    void SetEnterGround(Vector3 vPos, float groundY)
    {
        m_vVelocity = Vector3.zero;
        vPos.y = groundY;
        transform.position = vPos;
    }
}
