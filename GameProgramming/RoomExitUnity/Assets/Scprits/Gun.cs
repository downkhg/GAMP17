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
            GameObject objBullet = Instantiate(prefapsBullet, Vector3.zero, Quaternion.identity);
            objBullet.name = string.Format("{0}{1}", prefapsBullet.name, i);
            EnqueBullet(objBullet);
        }
        Reload();
    }

    public void EnqueBullet(GameObject gameObject)
    { 
        gameObject.SetActive(false);
        gameObject.transform.position = Vector3.zero;
        m_queBullet.Enqueue(gameObject);
        Debug.Log(string.Format("EnqueBullet({0}):{1}", m_queBullet.Count, gameObject.name));
    }

    public GameObject DequeBullet()
    {
        GameObject objBullet = m_queBullet.Dequeue();
        objBullet.SetActive(true);
        Debug.Log(string.Format("DequeBullet({0}):{1}", m_queBullet.Count, objBullet.name));
        return objBullet;
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
                GameObject objBullet = DequeBullet();
                if (objBullet)
                {
                    objBullet.transform.position = m_transMozzle.position;
                    Bullet bullet = objBullet.GetComponent<Bullet>();
                    if (bullet)
                    {
                        bullet.Initialize(this);
                        Rigidbody rigidbodyBullet = objBullet.GetComponent<Rigidbody>();
                        rigidbodyBullet.velocity = Vector3.zero;
                        rigidbodyBullet.AddForce(transform.forward * 300);
                        m_CurBulletCount--;
                    }
                }
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
