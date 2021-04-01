using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemList : MonoBehaviour
{
    public GameObject m_prefabButton;
    public List<GameObject> m_listItemButton = new List<GameObject>();
    public RectTransform m_recttrContent;
    public GridLayoutGroup m_gridLayoutGroupContent;
    
    public void InitItemList(Dynamic dynamic, GUIItemInfo guiItemInfo)
    {
        List<ItemManager.E_ITEM> listIventory = dynamic.m_listInventory;
        foreach (ItemManager.E_ITEM item in listIventory)
        //foreach (var item in listIventory)
        {
            Button cButton = CreateButton(item);
            cButton.onClick.AddListener(() => guiItemInfo.SetItem(item) );
            m_listItemButton.Add(cButton.gameObject);
        }
        ResizeContentRect();
    }

    public Button CreateButton(ItemManager.E_ITEM item)
    {
        Item cItem = GameManager.GetInstance().m_cItemManager.GetItem(item);
        GameObject objButton = Instantiate(m_prefabButton, m_recttrContent.transform);
        Button cButton = objButton.GetComponent<Button>();
        Text cButtonText = objButton.transform.GetComponentInChildren<Text>();
        cButtonText.text = cItem.name;
        return cButton;
    }

    public void ResizeContentRect()
    {
        Vector2 vRectSize = m_recttrContent.sizeDelta;
        Vector2 vCellSize = m_gridLayoutGroupContent.cellSize;
        vRectSize.y = vCellSize.y * m_listItemButton.Count;
        m_recttrContent.sizeDelta = vRectSize;
    }

    public void Release()
    {
        foreach (GameObject objButton in m_listItemButton)
        {
            Destroy(objButton);
        }
        m_listItemButton.Clear();
    }

    // Start is called before the first frame update
    void Start()
    {
        m_gridLayoutGroupContent = m_recttrContent.gameObject.GetComponent<GridLayoutGroup>();
    }
}
