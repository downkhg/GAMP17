using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gravity : MonoBehaviour
{
    public float m_fG = 9.8f;
    public Vector3 m_fDir = Vector3.down;

    private void FixedUpdate()
    {
        RaycastHit raycastHit;
        Ray ray = new Ray(transform.position, m_fDir);
      
        if (Physics.Raycast(ray, out raycastHit, m_fG))
        {
            if (raycastHit.distance > 0)
            {
                Vector3 vPos = transform.position;
                vPos += m_fDir * m_fG * Time.deltaTime;
                transform.position = vPos;
            }
        }
    }
}
