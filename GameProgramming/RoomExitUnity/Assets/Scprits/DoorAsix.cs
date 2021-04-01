using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DoorAsix : MonoBehaviour
{
    public float m_fAngle;
    public float m_fMaxAngle;

    public bool m_bOpen = false;
    public bool m_bStop = true;
  
    public void Open()
    {
        m_bStop = false;
    }

    private void Start()
    {
        m_bStop = true;
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space))
        {
            Open();
        }

        ProcessOpen();
    }

    void ProcessOpen()
    {
        if (m_bStop == false)
        {
            if (m_bOpen == false)
            {
                //반시계방향으로 회전하기위해서 축을 거꾸로 넣음.
                if (m_fAngle < m_fMaxAngle)
                {
                    m_fAngle += 1;
                    //transform.Rotate(Vector3.down * 1); //회전된각도에서 지정각도만큼 회전
                    //지정된 각도로 회전  
                }
                else
                {
                    m_bOpen = true;
                    m_bStop = true;
                }
            }
            else
            {
                if (m_fAngle > 0)
                {
                    m_fAngle -= 1;
                }
                else
                {
                    m_bOpen = false;
                    m_bStop = true;
                }
            }

            transform.localRotation = Quaternion.Euler(Vector3.down * m_fAngle);
        }
    }
}
