#!/bin/bash

# GPU Acceleration Script for Cub3D
# This script forces the use of NVIDIA GPU for rendering

echo "=== GPU Acceleration Setup for MiniRT ==="
echo "Configuring to use NVIDIA GPU..."

# Set environment variables to force NVIDIA GPU usage
export __NV_PRIME_RENDER_OFFLOAD=1
export __GLX_VENDOR_LIBRARY_NAME=nvidia
export __VK_LAYER_NV_optimus=NVIDIA_only

# Force GPU selection for OpenGL
export DRI_PRIME=1

# Set OpenGL to use GPU acceleration
export LIBGL_ALWAYS_INDIRECT=0

# Display GPU information
echo "GPU Information:"
if command -v nvidia-smi &> /dev/null; then
    nvidia-smi -L
else
    echo "NVIDIA tools not found, but GPU variables set"
fi

echo ""
echo "Environment variables set:"
echo "  __NV_PRIME_RENDER_OFFLOAD=1"
echo "  __GLX_VENDOR_LIBRARY_NAME=nvidia"
echo "  __VK_LAYER_NV_optimus=NVIDIA_only"
echo "  DRI_PRIME=1"
echo "  LIBGL_ALWAYS_INDIRECT=0"
echo ""

# Run Cub3D with GPU acceleration
echo "Starting miniRT with GPU acceleration..."
./miniRT "$@"
