using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIManager : MonoBehaviour
{
    public enum E_SCENCE_STATUS{ TITILE, GAMEOVER, THEEND, PLAY, MAX }
    public E_SCENCE_STATUS m_eCurStatus;
    public List<GameObject> m_listScence;

    public GUIIventory m_guiInventory;
    public GameObject m_objPopupLayer;

    public void ShowPopupLayer()
    {

        if (m_objPopupLayer.activeSelf == true)
        {
            m_objPopupLayer.SetActive(false);
            m_guiInventory.Show(false);
        }
        else
        {
           
            m_objPopupLayer.SetActive(true);
            m_guiInventory.Show(true);
        }
       
    }

    public Text m_textTimmer;

    public GameManager m_cGameManager;

    private void Awake()
    {
        m_cGameManager = GameManager.GetInstance();
        Debug.Log("GUIManager::Awake()");
    }

    public void SetTimmer(int curTime, int maxTime)
    {
        int nMinTime = maxTime - curTime;
        m_textTimmer.text = string.Format("남은시간: {0}", nMinTime);
    }

    void ShowScence(E_SCENCE_STATUS status)
    {
        for(int i = 0; i< (int)E_SCENCE_STATUS.MAX; i++)
        {
            if (i == (int)status)
                m_listScence[i].SetActive(true);
            else
                m_listScence[i].SetActive(false);
        }
    }

    public void SetStatus(int statusNumber)
    {
        SetStatus((E_SCENCE_STATUS)statusNumber);
    }
    //유한상태머신(FSM):상태를 바꿔주면 객체의 행동이 달라짐.
    public void SetStatus(E_SCENCE_STATUS status)
    {
        //객체가 존재하지않는 경우를 감안하여 장면이 바뀔때 확인한다.
        if (m_cGameManager) m_cGameManager = GameManager.GetInstance();
        Time.timeScale = 0;
        switch (status)
        {
            case E_SCENCE_STATUS.TITILE:

                break;
            case E_SCENCE_STATUS.GAMEOVER:
                break;
            case E_SCENCE_STATUS.THEEND:
                break;
            case E_SCENCE_STATUS.PLAY:
                Time.timeScale = 1;
                m_cGameManager.InitRoomObject();

               
                break;
        }
        ShowScence(status);
        m_eCurStatus = status;
    }

    public void UpdateStatus()
    {
        switch(m_eCurStatus)
        {
            case E_SCENCE_STATUS.TITILE:

                break;
            case E_SCENCE_STATUS.GAMEOVER:

                break;
            case E_SCENCE_STATUS.THEEND:

                break;
            case E_SCENCE_STATUS.PLAY:
                Dynamic player = m_cGameManager.m_cPlayer;
                SetTimmer(player.m_nTimmerCount, player.m_nMaxTimmer);

                if (Input.GetKeyDown(KeyCode.I))
                {
                    ShowPopupLayer();
                }
                break;
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        m_listScence = new List<GameObject>(transform.childCount);
        for(int i = 0; i < transform.childCount; i++)
        {
            Transform transformChild = transform.GetChild(i);
            Debug.Log("transformChild:"+i);
            m_listScence.Add(transformChild.gameObject);
        }
        SetStatus(m_eCurStatus);
    }

    // Update is called once per frame
    void Update()
    {
        UpdateStatus();
    }
}
