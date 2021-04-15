using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    Vector3 m_vStartPos;
    float m_fRange;
    Gun m_Gun;

    public float Range { get { return m_fRange; } set { m_fRange = value; } }

    public void Initialize(Gun gun)
    {
        m_Gun = gun;
        m_fRange = gun.Range;
    }

    private void Start()
    {
        m_vStartPos = this.transform.position;
    }

    private void Update()
    {
        Vector3 vPos = this.transform.position;
        //Vector3 vDist = vPos - m_vStartPos;
        //float fDist = vDist.magnitude;
        float fDist = Vector3.Distance(vPos,m_vStartPos);

        if (fDist >= m_fRange)
        {
            //Destroy(this.gameObject);
            m_Gun.EnqueBullet(gameObject);
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        //Destroy(other.gameObject);
        m_Gun.EnqueBullet(gameObject);
    }

    private void OnCollisionEnter(Collision collision)
    {
       // Destroy(collision.gameObject);
    }
}
