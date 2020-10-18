func simplifyPath(path string) string {
	var stack []string
	paths := strings.Split(path, "/")
	for _, path := range paths {
		if path == "" || path == "." {
			continue
		} else if path == ".." {
			if len(stack) > 0 {
				stack = stack[:len(stack)-1]
			}
		} else {
			stack = append(stack, path)
		}
	}
	return "/" + strings.Join(stack, "/")
}
