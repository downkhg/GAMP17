using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GUIStatusBar : MonoBehaviour
{
    public RectTransform m_rectBar;
    Vector2 m_vBarSize;
    public void SetStatus(float cur, float max)
    {
        float fRat = cur / max;
        RectTransform rect = m_rectBar;
        Vector2 vSize = rect.sizeDelta;
        vSize.x = m_vBarSize.x * fRat;
        rect.sizeDelta = vSize;
    }

    // Start is called before the first frame update
    private void Awake()
    {
        m_vBarSize = m_rectBar.sizeDelta;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
