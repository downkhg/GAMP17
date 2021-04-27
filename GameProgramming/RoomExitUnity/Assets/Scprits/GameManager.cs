using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public Player m_cPlayer;
    public Player m_cMonster;
    public GUIManager m_cGuiManager;
    public BoxCollider m_colliderBox;
    public ItemManager m_cItemManager;
    public Camera m_cCamera;

    public Dictionary<string,RoomObject> m_listRoomObject;

    public RoomObject GetRoomObject(string objname)
    {
        return m_listRoomObject[objname];
    }

    public void InitRoomObject()
    {
        m_listRoomObject = new Dictionary<string, RoomObject>();
        RoomObject[] roomObjects = GameObject.FindObjectsOfType<RoomObject>();
        for (int i = 0; i < roomObjects.Length; i++)
        {
            Debug.Log("RoomObject["+i+"]:"+roomObjects[i].gameObject.name);
            m_listRoomObject.Add(roomObjects[i].gameObject.name, roomObjects[i]);
        }
    }

    static GameManager m_cInstance;

    public static GameManager GetInstance()
    {
        return m_cInstance;
    }

    // Start is called before the first frame update
    void Awake()
    {
        m_cInstance = this;

        //m_cPlayer.SetInventory(ItemManager.E_ITEM.KEY);
        //m_cPlayer.SetInventory(ItemManager.E_ITEM.KEY01);
        //m_cPlayer.SetInventory(ItemManager.E_ITEM.KEY02);
        //m_cPlayer.SetInventory(ItemManager.E_ITEM.KEY03);
        //m_cPlayer.SetInventory(ItemManager.E_ITEM.KEY04);
        Debug.Log("GameManager::Awake("+gameObject.name+")");
    }

    private void Start()
    {
       
    }

    private void FixedUpdate()
    {
        //물리없는 충돌체크
        if (m_colliderBox == null) return;
        Vector3 vPos = m_colliderBox.transform.position;
        Vector3 vSize = (m_colliderBox.size * 0.5f);
        int nLayer = 1<<LayerMask.NameToLayer("Player");
        Collider[] colliders = Physics.OverlapBox(vPos, vSize, Quaternion.identity, nLayer);

        if(colliders.Length > 0)
        {
            for (int i = 0; i < colliders.Length; i++)
            {
                if (colliders[i].gameObject.name == "Player")
                    EventCheckTheEnd();
                Debug.Log("col:"+ colliders[i].gameObject.name);
            }
        }
    }

    private void OnDrawGizmos()
    {
        if (m_colliderBox == null) return;
        Vector3 vPos = m_colliderBox.transform.position;
        Vector3 vSize = m_colliderBox.size;
        Gizmos.DrawCube(vPos, vSize);
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Escape))
        {
            EvnetAppExit();
        }
    }

    void EvnetAppExit()
    {
        m_cPlayer.m_cGun.ReleaseBullet();
        m_cMonster.m_cGun.ReleaseBullet();
        Application.Quit();
        Debug.Log("EvnetAppExit()");
    }

    void EventCheckGameOver()
    {
        if (m_cPlayer.CheckGameOver())
            m_cGuiManager.SetStatus(GUIManager.E_SCENCE_STATUS.GAMEOVER);
    }

    void EventCheckTheEnd()
    {
        RoomObject roomObject = GetRoomObject("ExitDoor");
        if (roomObject == null) return;
        ExitDoor exitDoor = (ExitDoor)roomObject;

        if(exitDoor.CheckOpenDoor())
            m_cGuiManager.SetStatus(GUIManager.E_SCENCE_STATUS.THEEND);
    }

    public void EventStartPlay()
    {
        m_cGuiManager.SetStatus(GUIManager.E_SCENCE_STATUS.PLAY);
    }
}
