using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    [SerializeField]
    Transform transMozzle;

    public void Shot()
    {
        GameObject prefapsBullet = Resources.Load("Prefabs/Bullet") as GameObject;
        GameObject objBullet = Instantiate(prefapsBullet, transMozzle.position, Quaternion.identity);
        Rigidbody rigidbodyBullet = objBullet.GetComponent<Rigidbody>();
        rigidbodyBullet.AddForce(transform.forward * 300);
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
