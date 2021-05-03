using UnityEngine;

public class SimpleRigidBody : MonoBehaviour
{
    public float m_fGravity = 9.8f;
    public Vector3 m_fGravityDir = Vector3.down;
    public float m_fSpeed;
    public Vector3 m_vVelocity;
    public float m_fPower;
    public bool m_isGround = false;
    public bool m_isPreCollion = false;
    public Vector3 m_vGroudPos;
   
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
        float fDeltaTime = Time.deltaTime;
        Vector3 vPos = transform.position;
        

        //bool isCollision = GroundCheckRay(vPos);
        bool isCollision = GroundCheckShpre(vPos, m_fGravity * Time.deltaTime);
        //bool isCollision = GroundCheckCapsule(vPos, 0.5f);

        if (!m_isGround)
            m_vVelocity += m_fGravityDir * m_fGravity;

        transform.position += m_vVelocity * fDeltaTime;

        m_isPreCollion = isCollision;
    }

    bool GroundCheckRay(Vector3 vPos)
    {
        float fDist = 999999.0f;
        
        Ray ray = new Ray(vPos, m_fGravityDir);
        RaycastHit raycastHit;
        float fGroundY = -fDist;
        bool isCollision = false;
        if (Physics.Raycast(ray, out raycastHit, fDist))
        {
            m_vGroudPos = raycastHit.point;
            isCollision = true;
            Debug.DrawLine(vPos, vPos + m_fGravityDir * fDist, Color.green);
        }
        else
            Debug.DrawLine(vPos, vPos + m_fGravityDir * fDist, Color.red);

        //바닥이 없으면 충돌이 이상해짐.
        //Enter: 이전상태가 충돌되고, 현재상태가 충돌되지않음.
        if (m_isPreCollion && !isCollision)
        {
            m_isGround = true;
            SetEnterGround(transform.position, m_vGroudPos.y);
            Debug.Log("Ground Enter!");
        }
        //Exit: 이전상태가 충돌이 아니고, 현재상태가 충돌.
        else if (!m_isPreCollion && isCollision)
        {
            m_isGround = false;
            Debug.Log("Ground Exit!");
        }
        else if (!m_isPreCollion && !isCollision)
        {
            vPos.y = -fDist;
            m_vGroudPos = vPos;
        }


        return isCollision;
    }

    bool GroundCheckShpre(Vector3 vPos, float rad)
    {
        bool isCollision = false;

        Collider[] collisions = Physics.OverlapSphere(vPos, rad, 1 << LayerMask.NameToLayer("Ground"));
        if (collisions.Length > 0)
        {
            isCollision = true;
            //Debug.DrawLine(vPos, vPos + m_fGravityDir * fDist, Color.green);
        }
        //else
        //Debug.DrawLine(vPos, vPos + m_fGravityDir * fDist, Color.red);

        //Ray ray = new Ray(vPos, m_fGravityDir);
        //RaycastHit raycastHit;
        //if (Physics.Raycast(ray, out raycastHit, m_fGravity))
        //{
        //    m_vGroudPos = raycastHit.point;
        //}

        Vector3 vRayPos = GetComponent<Controller>().Player.transform.position;
        Ray ray = new Ray(vRayPos, m_fGravityDir);
        RaycastHit raycastHit;
        bool bRayCheck = false;
        if (Physics.Raycast(ray, out raycastHit, m_fGravity))
        {
            m_vGroudPos = raycastHit.point;
            bRayCheck = true;
            Debug.DrawLine(vRayPos, vRayPos + m_fGravityDir * m_fGravity, Color.green);
        }
        else
        {
            m_vGroudPos.y = -99999.0f;
            Debug.DrawLine(vRayPos, vRayPos + m_fGravityDir * m_fGravity, Color.red);
            SetEnterGround(transform.position, m_vGroudPos.y);
        }

        //바닥이 없으면 충돌이 이상해짐.
        //Enter: 이전상태가 충돌되지않고, 현재 상태가 충돌됨.
        if (m_isPreCollion && !isCollision)
        {
            m_isGround = true;
            SetEnterGround(transform.position, 0);
            Debug.Log("Ground Enter!");
        }
        //Exit: 이전상태가 충돌되고, 현재상태가 충돌안됨.
        else if (!m_isPreCollion && isCollision)
        {
            m_isGround = false;
            Debug.Log("Ground Exit!");
        }
        else if(!m_isPreCollion && !isCollision)
        {
            Debug.LogError("Ground Stay!");
           
           
        }

        return isCollision;
    }

    bool GroundCheckCapsule(Vector3 vPos, float rad)
    {
        Ray ray = new Ray(vPos, m_fGravityDir);
        bool isCollision = false;
        Vector3 vPosDown = vPos + Vector3.up * rad;
        Vector3 vPosUp = vPosDown + Vector3.up;
        Collider[] collisions = Physics.OverlapCapsule(vPosUp, vPosDown, rad, 1 << LayerMask.NameToLayer("Ground"));
        if (collisions.Length > 0)
        {
            isCollision = true;
            //Debug.DrawLine(vPos, vPos + m_fGravityDir * fDist, Color.green);
        }
        //else
        //Debug.DrawLine(vPos, vPos + m_fGravityDir * fDist, Color.red);


        //Enter: 이전상태가 충돌되지않고, 현재 상태가 충돌됨.      
        if (m_isPreCollion && !isCollision)
        {
            m_isGround = true;
            SetEnterGround(transform.position, 0);
            Debug.Log("Ground Enter!");
        }
        //Exit: 이전상태가 충돌되고, 현재상태가 충돌안됨.
        else if (!m_isPreCollion && isCollision)
        {
            m_isGround = false;
            Debug.Log("Ground Exit!");
        }

        return isCollision;
    }

    private void OnDrawGizmos()
    {
        //Gizmos.DrawSphere(this.transform.position, m_fGravity * Time.deltaTime);
        float rad = 0.5f;
        Vector3 vPos = transform.position;
        Vector3 vPosDown = vPos + Vector3.up * rad;
        Vector3 vPosUp = vPosDown + Vector3.up;
        Gizmos.color = Color.blue;
        Gizmos.DrawWireSphere(vPosUp, rad);
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

    private void OnCollisionEnter(Collision collision)
    {
        Debug.Log("OnCollisionEnter:"+collision.gameObject.name);
        m_isGround = true;
        SetEnterGround(transform.position,0);
    }

    private void OnCollisionExit(Collision collision)
    {
        Debug.Log("OnCollisionExit:" + collision.gameObject.name);
        m_isGround = false;
    }
}
