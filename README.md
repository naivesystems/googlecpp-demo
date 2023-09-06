# Google C++ Demo Guide

1. 将此repo克隆到本地

2. 建立`//.naivesystems/check_rules`路径，check_rules内容为：
```
googlecpp/g1168
googlecpp/g1190
googlecpp/g1193
googlecpp/g1194
googlecpp/g1203
```

3. 在repo根目录运行：
```
mkdir -p output && \
podman run --rm -v $PWD:/src:O -v $PWD/.naivesystems:/config:Z \
  -v $PWD/output:/output:Z \
  ${IMAGE_NAME} \
  /opt/naivesystems/misra_analyzer -show_results
```
其中`IMAGE_NAME`为analyzer的podman镜像名，默认为`naive.systems/analyzer/googlecpp:prod`。

4. 待分析运行完毕，结果将保存至`//output/results.nsa_results`

结果示例：
```
/src/demo.cc:15: [G1190][googlecpp-g1190]: Default arguments are banned on virtual functions, where they don't work properly, and in cases where the specified default might not evaluate to the same value depending on when it was evaluated

/src/demo.cc:31: [G1193][googlecpp-g1193]: Avoid using run-time type information (RTTI)

/src/demo.cc:43: [G1203][googlecpp-g1203]: Prefer sizeof(varname) to sizeof(type)

/src/demo.cc:46: [G1194][googlecpp-g1194]: Use C++-style casts

/src/src/demo.cc:13: [G1168][googlecpp-g1168]: Do not define implicit conversions. Use the explicit keyword for conversion operators and single-argument constructors
```
