using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GUIIventory : MonoBehaviour
{
    public GUIItemInfo guiItemInfo;
    public GUIItemList guiItemList;

    public void Show(bool use)
    {
        if (use == true)
        {
            Time.timeScale = 1;
            gameObject.SetActive(true);
            guiItemList.InitItemList(GameManager.GetInstance().m_cPlayer, guiItemInfo);
        }
        else
        {
            Time.timeScale = 0;
            gameObject.SetActive(false);
            guiItemList.Release();
        }
    }
}
