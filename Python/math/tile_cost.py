import sys

def tile_cost(h, w, cost):
	return h * w * cost

if __name__ == "__main__":
	if (len(sys.argv) == 1):
		print("Usage: python tile_cost <height> <width> <cost/m^2>")
	else:
		print(tile_cost(float(sys.argv[1]), float(sys.argv[2]), float(sys.argv[3])))