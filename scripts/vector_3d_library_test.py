import vector_3d

def main():
    vector1 = vector_3d.Vector3D()
    vector1.print()
    print(f"Vector1 length: {vector1.length()}\n")

    vector2 = vector_3d.Vector3D(3, 4, 0)
    vector2.print()
    print(f"Vector2 length: {vector2.length()}\n")

    vector3 = vector_3d.Vector3D([0, 5, 12])
    vector3.print()
    print(f"Vector3 length: {vector3.length()}\n")

    print("vector2 + vector3 = ")
    vector_3d.vectorAddition(vector2, vector3).print()
    print()

    print("vector2 - vector3 = ")
    vector_3d.vectorSubstraction(vector2, vector3).print()
    print()

    print("vector2 * vector3 = ")
    vector_3d.vectorDotProduct(vector2, vector3).print()
    print()

    vector3.normalize()
    print("Normalizing vector3")
    vector3.print()
    print(f"Now vector3 length: {vector3.length()}\n")

    print("vector4 = vector3")
    vector4 = vector3
    vector4.print()
    print(f"Vector4 length: {vector3.length()}\n")

if __name__ == "__main__":
    main()