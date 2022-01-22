const express = require("express");
const path = require("path");
const port = process.env.PORT || 3003;
const publicPath = path.join(__dirname, "public", "build");
const expressStaticGzip = require("express-static-gzip");
const app = express();
app.use(expressStaticGzip(publicPath));

app.get("/*", (req, res) => {
  res.sendFile(path.join(__dirname, "public", "build", "index.html"));
});

app.listen(port, () => {
  console.log(`started on port ${port}`);
});
