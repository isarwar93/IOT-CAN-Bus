import subprocess
import os 

dir_path = os.path.dirname(os.path.realpath(__file__))

try:
    # Capture the output and errors, if any
    result = subprocess.run(['bash', dir_path+"//firmware_builder.sh"], capture_output=True, text=True)

    # Print the output
    print("Output:")
    print(result.stdout)

    # Print any errors
    if result.stderr:
        print("Errors:")
        print(result.stderr)
        
except Exception as e:
    print(f"An error occurred: {e}")