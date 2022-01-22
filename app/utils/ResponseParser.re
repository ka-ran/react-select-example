let parseUnprocessedEntity = (json: Js.Json.t): Error.t => {
  Json.Decode.{
    title: "UnprocessedEntity",
    message:
      Belt.Option.getWithDefault(
        json |> optional(field("message", string)),
        "Provided values cannot be processed",
      ),
  };
};

let parseUnhandledError = (error: string): Error.t => {
  {title: "UnhandledError", message: error};
};

let execute =
    (
      ~request: Js.Promise.t(Response.t),
      ~successResponseParser: Js.Json.t => 'a,
    ) => {
  request
  |> Js.Promise.(
       then_((response: Response.t) => {
         switch (response) {
         | Success(data) =>
           Js.Promise.resolve(Belt.Result.Ok(data->successResponseParser))
         | UnprocessedEntity(res) =>
           Js.Promise.resolve(Belt.Result.Error(res->parseUnprocessedEntity))
         | Failure(message) =>
           Js.Promise.resolve(
             Belt.Result.Error(message->parseUnhandledError),
           )
         }
       })
     );
};
