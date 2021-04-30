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
   
    public void AddForce(Vector3 dir, float power)
    {
        m_vVelocity += dir * power;
    }
    private void Update()
    {
        
    }

    private void FixedUpdate()
    {
        //ProcessGravity();
        ProcessNoCollisionGravity();
    }

    void ProcessGravity()
    {
        float fDeltaTime = Time.deltaTime;
        Vector3 vPos = transform.position;
        float fDist = 999999.0f;

        Debug.DrawLine(vPos, vPos + m_fGravityDir * fDist, Color.red);
        Ray ray = new Ray(vPos, m_fGravityDir);
        RaycastHit raycastHit;
        if (Physics.Raycast(ray, out raycastHit, fDist))
        {
            
        }

        if(!m_isGround)
            m_vVelocity += m_fGravityDir * m_fGravity;

        transform.position += m_vVelocity * fDeltaTime;
    }

    void ProcessNoCollisionGravity()
    {
        float fDeltaTime = Time.deltaTime;
        Vector3 vPos = transform.position;
 
        if (vPos.y >= 0)
        {
            if (vPos.y > 0)
                m_vVelocity += m_fGravityDir * m_fGravity;// * fDeltaTime;

            transform.position += m_vVelocity * fDeltaTime;
        }
        else
        {
            SetEnterGround(vPos);
        }
    }

    void SetEnterGround(Vector3 vPos)
    {
        m_vVelocity = Vector3.zero;
        vPos.y = 0;
        transform.position = vPos;
    }

    private void OnCollisionEnter(Collision collision)
    {
        Debug.Log("OnCollisionEnter:"+collision.gameObject.name);
        m_isGround = true;
        SetEnterGround(transform.position);
    }

    private void OnCollisionExit(Collision collision)
    {
        Debug.Log("OnCollisionExit:" + collision.gameObject.name);
        m_isGround = false;
    }
}
