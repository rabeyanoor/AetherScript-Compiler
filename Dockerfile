# Stage 1: Build the React frontend
FROM node:20-slim AS frontend-builder
WORKDIR /app/frontend-react
COPY frontend-react/package*.json ./
RUN npm install
COPY frontend-react/ ./
RUN npm run build

# Stage 2: Create the runner container
FROM python:3.10-slim
WORKDIR /app

# Install build dependencies for the compiler (gcc, make, flex)
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    flex \
    && rm -rf /var/lib/apt/lists/*

# Copy backend requirements and install them
COPY backend/requirements.txt ./backend/requirements.txt
RUN pip install --no-cache-dir -r backend/requirements.txt

# Copy the rest of the workspace
COPY . .

# Copy built frontend assets
COPY --from=frontend-builder /app/frontend-react/dist ./frontend-react/dist

# Build the C compiler binary
RUN cd compiler && make clean && make

# Expose port 8000
EXPOSE 8000

# Run the backend FastAPI server
CMD ["python", "backend/main.py"]
