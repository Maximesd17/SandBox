import json
import sys

# Function to convert map data into a list of lists of GameObjects
def convert_map_to_game_objects(map_data):
    game_objects = []
    for row in map_data.splitlines():
        row_objects = []
        current_type = None
        current_count = 0
        for char in row:
            if char == "W":
                new_type = "WALL"
            elif char == "P":
                new_type = "PLATFORM"
            elif char == "S":
                new_type = "WATER"
            elif char == "E":
                new_type = "MUD"
            elif char == "G":
                new_type = "GROUND"
            else:
                new_type = "AIR"
            if new_type != current_type:
                if current_type is not None:
                    row_objects.append({
                        "type": current_type,
                        "texture": current_type.lower() + ".png",
                        "x-size": current_count
                    })
                current_type = new_type
                current_count = 1
            else:
                current_count += 1
        if current_type is not None:
            row_objects.append({
                "type": current_type,
                "texture": current_type.lower() + ".png",
                "x-size": current_count
            })
        game_objects.append(row_objects)
    return game_objects

def main():
    if len(sys.argv) < 2:
        print("Usage: python script.py input_map_file.txt")
        return

    input_file = sys.argv[1]
    with open(input_file, "r") as infile:
        map_data = infile.read()

    # Get the width and height
    width = map_data.index("\n")
    height = map_data.count("\n") + 1

    # Converting map data to game objects
    game_objects = convert_map_to_game_objects(map_data)

    # Building the final JSON structure
    json_data = [
        [
            {
                "width": width,
                "height": height
            },
            game_objects
        ]
    ]

    output_file = input_file.replace(".txt", ".json")

    # Writing JSON data to the output file
    with open(output_file, "w") as outfile:
        json.dump(json_data, outfile, indent=4)

    print(f"Successfully converted {input_file} to {output_file}.")

if __name__ == "__main__":
    main()
