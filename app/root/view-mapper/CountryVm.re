module CountryOption = {
  [@react.component]
  let make = (~flag_code: string, ~label: string) => {
    <div className="c-country-option">
      <span className={"flag-icon flag-icon-" ++ flag_code} />
      label->React.string
    </div>;
  };
};

let toSelectOptions =
    (countries: list(Country.t)): array(ReactSelect.selectOption) => {
  countries
  |> List.map((c: Country.t) =>
       (
         {
           value: c.label,
           label: <CountryOption flag_code={c.value} label={c.label} />,
         }: ReactSelect.selectOption
       )
     )
  |> Array.of_list;
};
