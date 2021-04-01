using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemInfo : MonoBehaviour
{
    [SerializeField]
    Image m_imgItem;
    [SerializeField]
    Text m_textItem;

    public void SetItem(ItemManager.E_ITEM item)
    {
        Item cItem = GameManager.GetInstance().m_cItemManager.GetItem(item);
        Sprite spriteItem = Resources.Load<Sprite>("Item/" + cItem.img);
        m_imgItem.sprite = spriteItem;
        m_textItem.text = cItem.comment;
    }

    // Start is called before the first frame update
    void Start()
    {
       
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.T))
        {
            SetItem(ItemManager.E_ITEM.KEY01);
        }
    }
}
