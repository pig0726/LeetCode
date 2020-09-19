package main

import "strings"

func simplifyPath(path string) string {
	strPath := strings.Split(path, "/")

	var simpPath []string

	for _, str := range strPath {
		if strings.EqualFold(str, "") {
			continue
		} else if strings.EqualFold(str, ".") {
			continue
		} else if strings.EqualFold(str, "..") {
			if len(simpPath) > 0 {
				simpPath = simpPath[:len(simpPath)-1]
			}
		} else {
			simpPath = append(simpPath, str)
		}
	}

	return "/" + strings.Join(simpPath, "/")

	return ""
}
