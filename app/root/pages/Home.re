%bs.raw
{|require("../../assets/scss/_all.scss")|};

[@react.component]
let make = () => {
  let countries = CountriesHook.useCountries();
  <div className="c-home">
    {switch (countries) {
     | Loading => <div className="loader" />
     | Live(countries) =>
       <CountrySelect options={CountryVm.toSelectOptions(countries)} />
     | Error(error) =>
       <div className="error"> {React.string(error.message)} </div>
     }}
  </div>;
};
