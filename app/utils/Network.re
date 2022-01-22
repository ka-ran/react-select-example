[@bs.send] external toString: Js.Promise.error => string = "toString";

let getRequest = (~requestUrl: string): Js.Promise.t('a) => {
  Fetch.fetchWithInit(
    requestUrl,
    Fetch.RequestInit.make(
      ~method_=Get,
      /* ~headers=
         Fetch.HeadersInit.make({
           "Content-Type": "application/json",
           "Accept": "application/json",
         }), */
      (),
    ),
  )
  |> Js.Promise.then_(response => {
       switch (Fetch.Response.status(response)) {
       | 200 =>
         response
         |> Fetch.Response.json
         |> Js.Promise.then_(result =>
              Js.Promise.resolve(Response.Success(result))
            )
       | _ =>
         Js.Promise.resolve(
           Response.UnprocessedEntity(
             [%bs.raw
               {|
                {
                  "title": "UnprocessedEntity",
                  "message": "Unprocessed Entity"
                }
              |}
             ],
           ),
         )
       }
     })
  |> Js.Promise.catch(error => {
       error->toString->Response.Failure->Js.Promise.resolve
     });
};
