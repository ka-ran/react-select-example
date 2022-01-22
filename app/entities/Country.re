type t = {
  label: string,
  value: string,
};

let decodeCountry = (json: Js.Json.t): t => {
  Json.Decode.{
    label: json |> field("label", string),
    value: json |> field("value", string),
  };
};

let parse = (json: Js.Json.t): list(t) => {
  json |> Json.Decode.list(decodeCountry);
};
