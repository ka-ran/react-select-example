const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const { CleanWebpackPlugin } = require("clean-webpack-plugin");

module.exports = {
  mode: "production",
  devServer: {
    port: 3456,
    open: true,
    historyApiFallback: true,
  },
  optimization: {
    usedExports: true,
  },
  context: __dirname,
  entry: [path.resolve(__dirname, "app", "root", "Index.bs.js")],
  output: {
    path: path.resolve("public/build/"),
    filename: "[name].[hash].bundle.js",
    publicPath: "/",
  },
  resolve: {
    modules: [path.resolve(__dirname, "node_modules")],
    extensions: [".bs.js", ".js", ".css"],
  },
  module: {
    rules: [
      {
        test: /\.(scss|css)$/,
        use: [
          { loader: "style-loader" },
          { loader: "css-loader" },
          { loader: "sass-loader" },
        ],
      },
      {
        test: /\.svg$/,
        use: [{ loader: "url-loader" }],
      },
    ],
  },
  plugins: [
    new HtmlWebpackPlugin({
      filename: "index.html",
      template: "index.html",
    }),
    new CleanWebpackPlugin(),
  ],
};
