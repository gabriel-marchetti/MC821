import io, os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

m = input().decode()
n = input().decode()

print(2*n+1)