import os

# Files to delete
files_to_delete = ["./src/adb_clnt.c","./src/adb_svc.c","./src/adb_xdr.c","./src/adb.h","./src/server"]

# Directory path for files
directory_path = os.path.dirname(os.path.abspath(__file__))

for file_name in files_to_delete:
    file_path = os.path.join(directory_path, file_name)
    try:
        os.remove(file_path)
        print(f"File {file_name} removed")

    except FileNotFoundError:
        print(f"File {file_name} not found")

    except Exception as e:
        print(f"Error removing {file_name}: {e}")