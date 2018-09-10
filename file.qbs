import qbs 1.0

Application {
    name: "%{ProjectName}"
    files: ["%{CppFileName}"]
    cpp.dynamicLibraries: ["sfml-audio", "sfml-graphics", "sfml-network", "sfml-window", "sfml-system"]
    Depends { name: "cpp" }
}
