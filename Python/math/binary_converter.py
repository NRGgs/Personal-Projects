import sys

def to_binary(n):
	if n > 1:
		to_binary(n // 2)
	print(n % 2, end='')

if __name__ == "__main__":
	if (len(sys.argv) == 1):
		print("Usage: python binary_converter <n>")
	else:
		to_binary(int(sys.argv[1]))