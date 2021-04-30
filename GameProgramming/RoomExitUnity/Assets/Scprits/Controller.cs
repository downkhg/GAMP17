using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Controller : MonoBehaviour
{
    [SerializeField]
    Player m_Player;
    Rigidbody m_rigidbody;

    public Player Player { get { return m_Player; } }
    protected Rigidbody Rigidbody { get { return m_rigidbody; } }

    // Start is called before the first frame update
    public void GetRigidbody()
    {
        //m_rigidbody = GetComponent<Rigidbody>();
        //Debug.Log("GetRigidbody:" + m_rigidbody.gameObject.name);
    }

    void Awake()
    {
        //GetRigidbody();   
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void Translate(Vector3 dir, float speed)
    {
        transform.Translate(dir * speed * Time.deltaTime); //로컬좌표이동
        //transform.position += dir * speed * Time.deltaTime; //월드좌표 이동
        //Rigidbody.velocity = Vector3.zero;
    }

    public void Rotation(Vector3 axis, float angleSpeed)
    {
        transform.Rotate(axis * angleSpeed);
        //Rigidbody.velocity = Vector3.zero;
    }

    public void Jump(Rigidbody rigidbody, float jumpPower)
    {
        //Rigidbody.AddForce(Vector3.up * jumpPower);
    }
}
