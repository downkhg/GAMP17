using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Door : MonoBehaviour
{
    public DoorAsix m_cDoorAsix;
    public bool m_bLook = false;

    public void Open()
    {
        m_cDoorAsix.Open();
    }

    private void OnMouseDown()
    {
        if(m_bLook == false)
            m_cDoorAsix.Open();
    }
}
