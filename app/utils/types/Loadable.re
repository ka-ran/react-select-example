type t('a) =
  | Loading
  | Live('a)
  | Error(Error.t);
