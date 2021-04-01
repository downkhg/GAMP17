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
            Translate(Vector3.forward.normalized, Dynamic.Speed);
        }
        if (Input.GetKey(KeyCode.DownArrow))
        {
            Translate(Vector3.back, Dynamic.Speed);
        }
        if (Input.GetKey(KeyCode.RightArrow))
        {
            Rotation(Vector3.up, Dynamic.AngleSpeed);
        }
        if (Input.GetKey(KeyCode.LeftArrow))
        {
           Rotation(Vector3.down, Dynamic.AngleSpeed);
        }
        if (Input.GetKeyDown(KeyCode.X))
        {
            Dynamic.Attack();
        }
        if (Input.GetKeyDown(KeyCode.Space))
        {
            Jump(Rigidbody, Dynamic.JumpPower);
        }
    }
}
