# Google C++ Demo Guide

This demo illustrates how to seamlessly integrate static code analysis into
your [GitHub Actions](https://docs.github.com/en/actions) workflow using the
[Google C++ Analyzer](https://github.com/naivesystems/googlecpp). By following
this guide, you can improve the code quality of your C++ projects and ensure
they adhere to the Google C++ Style Guide.

## Getting Started

To get started with static code analysis using the Google C++ Analyzer in your
GitHub Actions workflow, follow these steps:

1. Check Rules File: Before running the analysis, make sure to create a
directory path named `//.naivesystems/check_rules` at the root of your project
and define your desired check rules in it. For example:

```
googlecpp/g1168
googlecpp/g1190
googlecpp/g1193
googlecpp/g1194
googlecpp/g1203
```

These rules will guide the Google C++ Analyzer in checking your code against
the Google C++ Style Guide.

2. Workflow Configuration: Refer to the sample workflow configuration in
`//.github/workflows/googlecpp-analyzer.yml` for inspiration on how to set up
your own workflow. This file provides example workflow configurations and
trigger conditions.

## Analysis Results

Once the code analysis is completed as part of your GitHub Actions workflow,
the results will be saved in the `//.output/results.nsa_results` file. Here is
an example of what the results may look like:

```
/src/demo.cc:13: [G1168][googlecpp-g1168]: Do not define implicit conversions. Use the explicit keyword for conversion operators and single-argument constructors

/src/demo.cc:15: [G1190][googlecpp-g1190]: Default arguments are banned on virtual functions, where they don't work properly, and in cases where the specified default might not evaluate to the same value depending on when it was evaluated

/src/demo.cc:31: [G1193][googlecpp-g1193]: Avoid using run-time type information (RTTI)

/src/demo.cc:43: [G1203][googlecpp-g1203]: Prefer sizeof(varname) to sizeof(type)

/src/demo.cc:46: [G1194][googlecpp-g1194]: Use C++-style casts
```
