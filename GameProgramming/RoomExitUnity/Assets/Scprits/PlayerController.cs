using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : Controller
{
    // Start is called before the first frame update
    void Start()
    {
       
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.UpArrow))
        {
            Translate(Vector3.forward, Player.Speed);
        }
        if (Input.GetKey(KeyCode.DownArrow))
        {
            Translate(Vector3.back, Player.Speed);
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
            Jump(Rigidbody, Player.JumpPower);
        }
        if (Input.GetKeyDown(KeyCode.R))
        {
            Player.m_cGun.Reload();
        }
    }
}
