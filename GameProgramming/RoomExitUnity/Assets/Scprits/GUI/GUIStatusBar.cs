using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GUIStatusBar : MonoBehaviour
{
    public void SetStatus(float cur, float max)
    {
        float fRat = cur / max;
        RectTransform rect = GetComponent<RectTransform>();
        Vector2 vSize = rect.sizeDelta;
        vSize.x *= fRat;
        rect.sizeDelta = vSize;
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
