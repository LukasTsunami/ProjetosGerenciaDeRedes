module.exports = function formatBufferAsJson(buffer) {
  return Object.fromEntries(
    new URLSearchParams(
      buffer
        .toString()
        .replace("\r", "")
        .replace("\n", "")
    )
  );
};
