using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ToolKit : RoomObject
{
    public override bool CheckItem(Dynamic dynamic)
    {
        //키조각을 모두 삭제하고 가지고 있는 아이템을 넘겨준다.

        List<ItemManager.E_ITEM> listIventory = dynamic.m_listInventory;

        int nCount = 0;
        foreach(ItemManager.E_ITEM item in listIventory)
        {
            if (item == ItemManager.E_ITEM.KEY01) nCount++;
            if (item == ItemManager.E_ITEM.KEY02) nCount++;
            if (item == ItemManager.E_ITEM.KEY03) nCount++;
            if (item == ItemManager.E_ITEM.KEY04) nCount++;
        }
        if(nCount == 4)
        {
            listIventory.Remove(ItemManager.E_ITEM.KEY01);
            listIventory.Remove(ItemManager.E_ITEM.KEY02);
            listIventory.Remove(ItemManager.E_ITEM.KEY03);
            listIventory.Remove(ItemManager.E_ITEM.KEY04);
            base.CheckItem(dynamic);
        }

        return false;
    }
}
