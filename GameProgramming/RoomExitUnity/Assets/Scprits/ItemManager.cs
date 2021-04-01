using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[Serializable]
public class Item
{
    public string name;
    public string comment;
    public string img;
    public Item(string name, string comment, string img)
    {
        this.name = name;
        this.comment = comment;
        this.img = img;
    }
}

public class ItemManager : MonoBehaviour
{
    public enum E_ITEM { NONE = -1,KEY01, KEY02 , KEY03 , KEY04, KEY, MAX }
    [SerializeField]
    List<Item> listItems; //vector와 동일함. 동적배열

    public void Initialize()
    {
        int nCapacity = (int)E_ITEM.MAX;
        listItems = new List<Item>(nCapacity);//배열을 5개까지 할당할수있는 메모리를 확보
        //실제 객체의 추가는 add를 통해 이루어진다.
        listItems.Add(new Item("Key01","나머지 조각이 필요하다","key01"));
        listItems.Add(new Item("Key02", "나머지 조각이 필요하다", "key02"));
        listItems.Add(new Item("Key03", "나머지 조각이 필요하다", "key03"));
        listItems.Add(new Item("Key04", "나머지 조각이 필요하다", "key04"));
        listItems.Add(new Item("Key", "문을 열고 탈출할 수 있을 거 같다.", "key"));
    }

    public void Release()
    {
        //C#에는 가비지컬럭터가 있으므로 동적할당된메모리를 따로 제거하지않아도됨.
        listItems.Clear();
    }

    public Item GetItem(E_ITEM eItem)
    {
        return listItems[(int)eItem];
    }

    // Start is called before the first frame update
    void Awake()
    {
        Initialize();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnDestroy()
    {
        Release();
    }
}
