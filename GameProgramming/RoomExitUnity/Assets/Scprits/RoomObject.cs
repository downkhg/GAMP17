using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RoomObject : MonoBehaviour
{
    public ItemManager.E_ITEM m_eItem;
  
    public virtual bool CheckItem(Dynamic dynamic)
    {
        Debug.Log("RoomObject::CheckItem 1 ");
        if (m_eItem != ItemManager.E_ITEM.NONE)
        {
            Debug.Log("RoomObject::CheckItem Event Strart ");
            dynamic.SetInventory(m_eItem);
            m_eItem = ItemManager.E_ITEM.NONE;
            Debug.Log("RoomObject::CheckItem Event End ");
            return false;
        }
        Debug.Log("RoomObject::CheckItem 2 ");
        return false;
    }
}
