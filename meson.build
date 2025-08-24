project('my_project', 'cpp', version: '0.1.0',
        default_options: [
                'cpp_std=c++20',  # 使用 C++20 标准
                'warning_level=3',
        ]
)

# 查找 Python3 解释器和相关信息
python = import('python').find_installation('python', required: true)
python_dep = python.dependency()

# 查找 pybind11（假设已安装）
pybind11_dep = dependency('pybind11', required: true)
zlib = dependency('zlib')
# 顶层 meson.build
gtest_dep = dependency('gtest', main : true, required : true) # 查找系统 GTest




# 定义 Python 扩展模块
python.extension_module(
        '_my_package',  # 模块名称，生成的 .so 文件将命名为 my_package.cpython-*.so
        sources: ['src/my_package/cpp/binding.cpp', 'src/my_package/cpp/my_code.cpp'],
        dependencies: [python_dep, pybind11_dep],
        install: true,
        install_dir: python.get_install_dir() / 'my_package'
)

# 安装 Python 源代码
python.install_sources(
        ['src/my_package/__init__.py', 'src/my_package/module.py'],
        subdir: 'my_package'
)

main = executable(
        'main',
        'main.cpp'
)

# 创建测试可执行文件
test_math = executable(
        'test_math_utils',
        'testA.cpp',
        dependencies: [
                gtest_dep,      # GTest 依赖

        ],
        install: false,
)

# 注册测试
#test('Math utils tests', test_math, timeout: 60)
test('Math utils tests', main, timeout: 60)