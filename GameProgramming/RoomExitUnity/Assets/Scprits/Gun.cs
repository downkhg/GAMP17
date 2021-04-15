using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    [SerializeField]
    Transform m_transMozzle;
    [SerializeField]
    float m_fRange;
    [SerializeField]
    int m_MaxBulletCount;
    int m_CurBulletCount;

    public int MaxBulletCount { get { return m_MaxBulletCount; } }
    public int CurBulletCount { get { return m_CurBulletCount; } }

    Queue<GameObject> m_queBullet;

    public Queue<GameObject> BulletFull { get { return m_queBullet; } }

    public void InitializeBullet()
    {
        GameObject prefapsBullet = Resources.Load("Prefabs/Bullet") as GameObject;
        m_queBullet = new Queue<GameObject>();
        for(int i = 0; i < m_MaxBulletCount; i++)
        {
            GameObject gameObject = Instantiate(prefapsBullet, Vector3.zero, Quaternion.identity);
            gameObject.SetActive(false);
            m_queBullet.Enqueue(gameObject);
        }
        Reload();
    }

    public void EnqueBullet(GameObject gameObject)
    {
        gameObject.SetActive(false);
        gameObject.transform.position = Vector3.zero;
        m_queBullet.Enqueue(this.gameObject);
    }

    public void Reload()
    {
        m_CurBulletCount = m_MaxBulletCount;
    }

    public float Range { get{ return m_fRange; } }

    public bool Shot()
    {
        //GameObject prefapsBullet = Resources.Load("Prefabs/Bullet") as GameObject;
        //GameObject objBullet = Instantiate(prefapsBullet, m_transMozzle.position, Quaternion.identity);
        //Bullet bullet = objBullet.GetComponent<Bullet>();
        //bullet.Range = m_fRange;
        //Rigidbody rigidbodyBullet = objBullet.GetComponent<Rigidbody>();
        //rigidbodyBullet.AddForce(transform.forward * 300);


        if (m_queBullet != null && m_queBullet.Count > 0)
        {
            if (m_CurBulletCount > 0)
            {
                GameObject objBullet = m_queBullet.Dequeue();
                objBullet.SetActive(true);
                objBullet.transform.position = m_transMozzle.position;
                Bullet bullet = objBullet.GetComponent<Bullet>();
                bullet.Initialize(this);
                Rigidbody rigidbodyBullet = objBullet.GetComponent<Rigidbody>();
                rigidbodyBullet.AddForce(transform.forward * 300);
                m_CurBulletCount--;
                return true;
            }
        }
        return false;
    }

    // Start is called before the first frame update
    void Start()
    {
        InitializeBullet();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
