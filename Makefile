.PHONY: format
format:
	find include -name '*pp' -type f | xargs clang-format -i
