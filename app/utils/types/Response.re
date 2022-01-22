type t =
  | Success(Js.Json.t)
  | UnprocessedEntity(Js.Json.t)
  | Failure(string);
