using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : Controller
{
    SimpleRigidBody m_cSimpleRigidBody;
    // Start is called before the first frame update
    void Start()
    {
        m_cSimpleRigidBody = GetComponent<SimpleRigidBody>();
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.UpArrow))
        {
            Translate(Vector3.forward, Player.Speed);
            //m_cSimpleRigidBody.Translate(transform.forward, Player.Speed);
        }
        if (Input.GetKey(KeyCode.DownArrow))
        {
            Translate(Vector3.back, Player.Speed);
            //m_cSimpleRigidBody.Translate(transform.forward * -1, Player.Speed);
        }
        if (Input.GetKey(KeyCode.RightArrow))
        {
            Rotation(Vector3.up, Player.AngleSpeed);
        }
        if (Input.GetKey(KeyCode.LeftArrow))
        {
           Rotation(Vector3.down, Player.AngleSpeed);
        }
        if (Input.GetKeyDown(KeyCode.X))
        {
            Player.Attack();
        }
        if (Input.GetKeyDown(KeyCode.Space))
        {
            m_cSimpleRigidBody.AddForce(Vector3.up, Player.JumpPower);
        }
        if (Input.GetKeyDown(KeyCode.R))
        {
            Player.m_cGun.Reload();
        }
    }
}
