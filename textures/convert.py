import os
from subprocess import run

def png_to_xpm():
    current_dir = os.getcwd()
    png_files = [f for f in os.listdir(current_dir) if f.endswith('.png')]
    
    for png_file in png_files:
        input_path = os.path.join(current_dir, png_file)
        output_path = os.path.join(current_dir, png_file.rsplit('.', 1)[0] + '.xpm')
        
        try:
            run(['convert', input_path, output_path], check=True)
            print(f"Converted {png_file}")
        except Exception as e:
            print(f"Error: Can't convert {png_file} \n{e}")

if __name__ == "__main__":
    png_to_xpm()
