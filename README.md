# Google C++ Demo Guide

## Running Code Analysis with GitHub Actions

[Google C++ Analyzer](https://github.com/naivesystems/googlecpp) can be
seamlessly integrated into your
[GitHub Actions](https://docs.github.com/en/actions) workflow. Please refer to
`//.github/workflows/googlecpp-analyzer.yml` for sample workflow configurations
and trigger conditions.

## Manually Building and Running Google C++ Analyzer Locally

1. Clone the [Google C++ Analyzer](https://github.com/naivesystems/googlecpp)
repository locally and run `make` to build the
image. The default image name will be `naive.systems/analyzer/googlecpp:prod`.

2. Clone this repository to your local machine.

3. Create a directory path named `//.naivesystems/check_rules` and define your
check rules within the file named `check_rules`. For example:
```
googlecpp/g1168
googlecpp/g1190
googlecpp/g1193
googlecpp/g1194
googlecpp/g1203
```

4. In the root directory of this repository, run the following command:
```
mkdir -p output && \
podman run --rm -v $PWD:/src:O -v $PWD/.naivesystems:/config:Z \
  -v $PWD/output:/output:Z \
  naive.systems/analyzer/googlecpp:prod \
  /opt/naivesystems/misra_analyzer -show_results
```

5. Once the code analysis is completed, the results will be saved in
`//output/results.nsa_results`. Example of the results:
```
/src/demo.cc:13: [G1168][googlecpp-g1168]: Do not define implicit conversions. Use the explicit keyword for conversion operators and single-argument constructors

/src/demo.cc:15: [G1190][googlecpp-g1190]: Default arguments are banned on virtual functions, where they don't work properly, and in cases where the specified default might not evaluate to the same value depending on when it was evaluated

/src/demo.cc:31: [G1193][googlecpp-g1193]: Avoid using run-time type information (RTTI)

/src/demo.cc:43: [G1203][googlecpp-g1203]: Prefer sizeof(varname) to sizeof(type)

/src/demo.cc:46: [G1194][googlecpp-g1194]: Use C++-style casts
```
