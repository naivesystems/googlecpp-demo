# Demo of Google C++ Style Analysis

This is a demo repository to show how to use NaiveSystems Analyze to enforce
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
in your own repository.

NOTE:
In our documentation, we will use `//` to denote the root of repositories.

Use [`//.github/workflows/googlecpp-analysis.yml`](https://github.com/naivesystems/googlecpp-demo/blob/main/.github/workflows/googlecpp-analysis.yml)
as a template to run Google C++ Style Analysis in GitHub Actions. Make sure
to use the `fetch-depth: 0` option provided by `actions/checkout`.

## Analysis Results

Analysis results are currently shown as GitHub Actions annotations. A custom
[problem matcher](https://github.com/naivesystems/googlecpp-image/blob/main/matcher.json)
is used for this purpose, so there is a limit of 10 reported results per run.
Only results relevant to the current code changes are reported.

TODO:
Put a screenshot here.

TODO:
Publish SARIF and integrate with GitHub Code Scanning.

## Rule Settings

By default, all guidelines (a.k.a. rules) in [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
are enforced by the analyzer. To customize the set of rules to use or specific
rule settings, create a configuration file at `//.naivesystems/check_rules` in
your repository. The complete set of rules is listed [here](https://github.com/naivesystems/googlecpp-image/blob/main/google_cpp.check_rules.txt).

TODO:
Publish the correspondence between the rule IDs and the actual rule texts.
