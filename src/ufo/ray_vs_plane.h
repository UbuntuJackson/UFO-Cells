float RayVsPlane(Ray3 _ray, Triangle3 tri){
    Vector3 n = CrossProduct(tri.p1, tri.p2, tri.p3);
    float a = n.x * (ray.p2.x - ray.p1.x) +
        n.y * (ray.p2.y - ray.p1.y) +
        n.z * (ray.p2.z - ray.p1.z);

    float b = ray.p1.x * n.x + ray.p1.y * n.y + ray.p1.z * n.z

    float c = tri.p1.x * n.x + tri.p1.y * n.y + tri.p1.z * n.z;

    float t = -(b-c)/a;
    return t;
}