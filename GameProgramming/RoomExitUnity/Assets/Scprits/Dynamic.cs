using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dynamic : MonoBehaviour
{
    [SerializeField]
    float m_fSpeed;
    [SerializeField]
    float m_fAngleSpeed;
    [SerializeField]
    float m_fJumpPower;
    [SerializeField]
    float m_fShotPower;
    [SerializeField]
    float m_fAttackRange;

    public float Speed { get { return m_fSpeed; } }
    public float AngleSpeed { get { return m_fAngleSpeed; } }
    public float JumpPower { get { return m_fJumpPower; } }
    public float ShotPower { get { return m_fShotPower; } }
    public float AttakRange { get { return m_fAttackRange; } }

    public Gun m_cGun;
    

    public Collider m_colliderTarget;

    public List<ItemManager.E_ITEM> m_listInventory;

    public int m_nTimmerCount = 0;
    public int m_nMaxTimmer = 180;

    public bool CheckGameOver()
    {
        return (m_nTimmerCount >= m_nMaxTimmer);
    }

    public void SetInventory(ItemManager.E_ITEM item)
    {
        m_listInventory.Add(item);
    }

    public ItemManager.E_ITEM GetIventory(int idx)
    {
        return m_listInventory[idx];
    }

    public void DeleteIventoryItem(ItemManager.E_ITEM item)
    {
        m_listInventory.Remove(item);
    }

    public bool ExitIventoy(ItemManager.E_ITEM item)
    {
        //람다식: 무명함수
        return m_listInventory.Exists( x =>  x == item );
    }
    //객체 활성화 전에 호출됨.
    private void Awake()
    {
        
    }

    // Start is called before the first frame update
    void Start()
    {
      
    }

    float m_fTimeCounter;

    public void Attack()
    {
        //GameObject prefapsBullet = new GameObject();
        //Rigidbody rigidbody = prefapsBullet.AddComponent<Rigidbody>();
        //rigidbody.useGravity = false;
        //MeshFilter meshFilter = prefapsBullet.AddComponent<MeshFilter>();

        //Mesh mesh = new Mesh();
        //mesh.vertices = new Vector3[3];
        //mesh.vertices[0] = new Vector3(0.5f, 0.5f, 0);
        //mesh.vertices[1] = new Vector3(-0.5f, 0.5f, 0);
        //mesh.vertices[2] = new Vector3(-0.5f, -0.5f, 0);

        //Debug.DrawLine(mesh.vertices[0], mesh.vertices[1]);
        //Debug.DrawLine(mesh.vertices[1], mesh.vertices[2]);
        //Debug.DrawLine(mesh.vertices[2], mesh.vertices[0]);

        //mesh.normals = new Vector3[3];
        //mesh.normals[0] = Vector3.forward;
        //mesh.normals[1] = Vector3.forward;
        //mesh.normals[2] = Vector3.forward;

        //meshFilter.mesh = mesh;
        //SphereCollider sphereCollider = prefapsBullet.AddComponent<SphereCollider>();
        //MeshRenderer meshRenderer = prefapsBullet.AddComponent<MeshRenderer>();
        //Material material = Resources.Load("Materials/Wall") as Material;
        //Renderer renderer = prefapsBullet.GetComponent<Renderer>();
        //renderer.material = material;


        //GameObject prefapsBullet = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        //Rigidbody rigidbody = prefapsBullet.AddComponent<Rigidbody>();
        //rigidbody.useGravity = false;
        //rigidbody.isKinematic = true;
        //SphereCollider sphereCollider = prefapsBullet.AddComponent<SphereCollider>();
        //sphereCollider.isTrigger = false;
        //prefapsBullet.transform.position = transform.position;
        //prefapsBullet.transform.rotation = transform.rotation;
        //rigidbody.AddForce(Vector3.forward * m_fShotPower);

        m_cGun.Shot();
    }

    void PrefabBullet()
    {
        GameObject prefapsBullet = Resources.Load("Prefabs/Bullet") as GameObject;
        GameObject objBullet = Instantiate(prefapsBullet, transform.position, transform.localRotation);
        Rigidbody rigidbodyBullet = objBullet.GetComponent<Rigidbody>();
        rigidbodyBullet.AddForce(transform.forward * 300);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void FixedUpdate()
    {
        
    }

   
    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(this.transform.position, m_fAttackRange);
    }

    private void OnGUI()
    {
        int idx = 0;
        foreach(ItemManager.E_ITEM item in m_listInventory)
        {
            GUI.Box(new Rect(0, 20 * idx, 100, 20), item.ToString());
            idx++;
        }
    }
    //충돌체끼리 물리리연산으로 충돌할때 호출되는 함수.
    private void OnCollisionEnter(Collision collision)
    {
       GameObject  objCollison =  collision.gameObject;
        Debug.Log("CollisonEnter:"+objCollison.name);
        if(objCollison)
        {
            if (objCollison.tag == "CollisionEvent")
            {
                RoomObject roomObject = objCollison.GetComponent<RoomObject>();
                if (roomObject)
                    roomObject.CheckItem(this);
            }
        }
    }
}
