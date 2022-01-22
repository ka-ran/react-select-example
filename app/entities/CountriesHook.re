let useCountries = () => {
  let (countries, updateCountries) = React.useState(_ => Loadable.Loading);

  let fetchCountries =
      (~onSuccess: list(Country.t) => unit, ~onError: Error.t => unit) => {
    ResponseParser.execute(
      ~request=
        Network.getRequest(
          ~requestUrl=
            "https://gist.githubusercontent.com/rusty-key/659db3f4566df459bd59c8a53dc9f71f/raw/4127f9550ef063121c564025f6d27dceeb279623/counties.json",
        ),
      ~successResponseParser=Country.parse,
    )
    |> Js.Promise.then_((result: Belt.Result.t('a, 'b)) => {
         Belt.Result.(
           switch (result) {
           | Ok(data) => Js.Promise.resolve(onSuccess(data))
           | Error(err) => Js.Promise.resolve(onError(err))
           }
         )
       });
  };

  React.useEffect0(() => {
    let _ =
      fetchCountries(
        ~onSuccess=data => updateCountries(_ => Loadable.Live(data)),
        ~onError=error => updateCountries(_ => Loadable.Error(error)),
      );
    None;
  });
  countries;
};
