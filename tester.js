import express from "express";
import fetch from "node-fetch"; // or use global fetch if supported

const app = express();
app.use(express.json());

app.get("/api/proxy-data", async (req, res) => {
  try {
    const apiRes = await fetch("https://api.example.com/data", {
      headers: {
        "Authorization": `Bearer ${API_KEY}`,
        "Accept": "application/json",
      },
    });
    if (!apiRes.ok) {
      const text = await apiRes.text();
      return res.status(apiRes.status).send(text);
    }
    const data = await apiRes.json();
    // Optionally filter or sanitize data before returning to client
    res.json(data);
  } catch (err) {
    console.error("Proxy error:", err);
    res.status(500).json({ error: "upstream request failed" });
  }
});

app.listen(3000, () => console.log("Server listening on http://localhost:3000"));
